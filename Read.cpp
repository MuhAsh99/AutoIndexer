//
// Created by Muhammad Ashraf on 2/22/22.
//
#include "Read.h"
#include "DSVector.h"
#include "DSString.h"
#include "Pages.h"
#include "stdlib.h"
#include "Keyword.h"


void Read::openFile(char**file) {
    std::ifstream myFile(file[1]);
    if (myFile.is_open()) {
        std::cout << "yippee" << std::endl;
        Pages* page = new Pages;
        while (!myFile.eof()) {
            char *buffer = new char[1000];
            myFile.getline(buffer, 1000);
            DSString temp(buffer);//do loop for this, also grab ID, and store into vector
            if(temp.getLength() < 1){
                continue;
            }
            for(int i = 0; i < temp.getLength(); i++){
                if(temp[0] == '<') {
                    if (temp[1] == '-') {
                        pageStore.push_back(*page); //place page number into vector
                        delete page;
                        break;
                    } else {

                        DSString pageNum;
                        for (int j = 1; j < temp.getLength(); j++){
                            if(temp[j] == '>'){
                                pageNum = temp.substring(1, j-1); //grab number in-between carrots and store
                                break;
                            }
                        }

                        // store page num in
                        int num = pageNum.toInt(); //convert DSString to an int
                            pageStore.push_back(*page); //place page number into vector
                            delete page; //deallocate


                        page = new Pages(); //create new set of Pages
                        page->setPageNum(num); //set the current page count

                }
                } else{

                page->setStorage(temp.toLower());

                }
            }

        }
        myFile.close();
        openFile2(file);

    }

     else {
            std::cout << "no bueno" << std::endl;
        }

    }

void Read::openFile2(char **file) {
    std::ifstream myFile2(file[2]);
    if (myFile2.is_open()) {
        std::cout << "yippee" << std::endl;
        Keyword coolKey;
        while (!myFile2.eof()) {
            char *buffer = new char[1000];
            myFile2.getline(buffer, 1000);
            DSString temp(buffer);//do loop for this, also contents, and store into temp
            if(temp.getLength() < 1){
                continue;
            }
            coolKey.setKeyStorage(temp.toLower()); //convert to lower case
            myKeys.push_back(coolKey); //push back lower case keys into vector

        }
        myFile2.close();
        crossReference(); //call crossReference
        print(file); //print file
    }
}

    void Read::crossReference() {


        //loop that goes through and checks each vector
       for(int i = 0; i < pageStore.sizeOf(); i++){

           for(int j = 0; j < myKeys.sizeOf(); j++ ){
                if(pageStore[i].getStorage().contains(myKeys[j].getKeyStorage())){
                    myKeys[j].setKeyCount(pageStore[i].getPageNum()); //stores page numbers that keys appear into vector
                }
           }
       }



}

void Read::print(char **file) {

    std::ofstream outPut(file[3]);

    myKeys.insertionSort();

    char prevFirst;
    for(int i = 0; i < myKeys.sizeOf(); i++){
        if(myKeys[i].getKeyCount().sizeOf() == 0){
            continue;
        }
        char first = myKeys[i].getKeyStorage()[0];
        if(isalpha(first) != 0){
            first = toupper(first);
        } //shifts letter to upper case
        if(first != prevFirst){
            prevFirst = first;
            outPut<<"["<<first<<"]" <<std::endl;
        }//gets rid of repeated letters



        outPut<<myKeys[i].getKeyStorage() << ": "; //prints word and colon after it


        outPut<<myKeys[i].getKeyCount()[0]; //gets page number that word appears on



        DSVector<DSString> limitCounter;
        limitCounter.push_back(myKeys[i].getKeyStorage());







        for(int j = 1; j < myKeys[i].getKeyCount().sizeOf(); j++){

            outPut<<", " << myKeys[i].getKeyCount()[j];

        }

        outPut<<std::endl;

            outPut << std::endl;


    }
    outPut.close();

}




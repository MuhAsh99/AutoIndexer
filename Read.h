//
// Created by Muhammad Ashraf on 2/22/22.
//

#ifndef INC_21F_PA02_READ_H
#define INC_21F_PA02_READ_H

#include "Read.h"
#include "DSVector.h"
#include "DSString.h"
#include <fstream>
#include "Pages.h"
#include "Keyword.h"

class Read{

public:

    void openFile(char**file);

    void openFile2(char**file);

    void textSplit(DSString text, Pages& p);

    void textSplit2(DSString text, Keyword& k);

    void crossReference();

    void print(char**file);



private:

    DSString line;
    DSString words;
    DSVector<Pages> pageStore;
    DSVector<Keyword> myKeys;

};

#endif //INC_21F_PA02_READ_H

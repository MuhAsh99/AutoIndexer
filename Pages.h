//
// Created by Muhammad Ashraf on 2/22/22.
//

#ifndef INC_21F_PA02_PAGES_H
#define INC_21F_PA02_PAGES_H

#include "DSVector.h"


class Pages{

public:
    Pages();
    DSString& getStorage(){return storage;}
    void setStorage(DSString words);
    int getPageNum() {return pageCount;}
    void setPageNum(int p);


private:

    int pageCount;
    DSString storage;

};
#endif //INC_21F_PA02_PAGES_H

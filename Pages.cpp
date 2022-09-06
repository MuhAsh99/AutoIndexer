//
// Created by Muhammad Ashraf on 2/22/22.
//

#include "Pages.h"

Pages::Pages(){
    pageCount = 0;
    storage = "";
}

void Pages::setPageNum(int p) {
    pageCount = p;
}

void Pages::setStorage(DSString words) {
    storage = storage + " " + words;
}

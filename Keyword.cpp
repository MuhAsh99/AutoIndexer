//
// Created by Muhammad Ashraf on 2/23/22.
//

#include "Keyword.h"

Keyword::Keyword() {
    keys = "";
}

void Keyword::setKeyStorage(DSString words) {
    keys = words;
}

void Keyword::setKeyCount(int k) {
    keyCount.push_back(k);
}

bool Keyword::operator> (Keyword k){

    return (keys[0] > k.keys[0]);

}

bool Keyword::operator>= (Keyword k){

    return (keys[0] > k.keys[0]);

}

//
// Created by Muhammad Ashraf on 2/23/22.
//

#ifndef INC_21F_PA02_KEYWORD_H
#define INC_21F_PA02_KEYWORD_H

#include "DSVector.h"

class Keyword{

public:
    Keyword();
    DSString& getKeyStorage(){return keys;}
    void setKeyStorage(DSString words);
    DSVector<int> getKeyCount() {return keyCount;}
    void setKeyCount(int k);
    bool operator> (Keyword k);
    bool operator>= (Keyword k);
private:
    DSVector<int> keyCount;
    DSString keys;
};

#endif //INC_21F_PA02_KEYWORD_H

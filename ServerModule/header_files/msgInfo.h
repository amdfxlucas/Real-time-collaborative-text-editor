//
// Created by giova on 10/10/2019.
//

#ifndef SERVERMODULE_MSGINFO_H
#define SERVERMODULE_MSGINFO_H

#include <string>
#include "symbol.h"

class msgInfo {

private:
    int type; //0 = 'insertion'; 1 = 'removal'; 2 = 'format'
    int editorId;
    symbol s;
    int newIndex; //this param will assume the meaning of 'format' if we're using type 2

public:
    msgInfo(int type, int editorId, symbol s);
    msgInfo(int type, int editorId, symbol s, int newIndex);
    int getType() const;
    int getEditorId();
    symbol getSymbol() const;
    int getNewIndex() const;
    std::string toString();
};


#endif //SERVERMODULE_MESSAGE_H

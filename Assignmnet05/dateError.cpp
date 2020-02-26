#include "dateError.h"
#include <string>
DateException::DateException(const string& m ="" ){
        msg = m;
    }
    string DateException::what(){
        return msg;
    }
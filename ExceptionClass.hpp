//
//  ExceptionClass.hpp
//  Sistema de Controle Bancário
//
//  Created by Alice Diniz Ferreira on 11/2/19.
//  Copyright © 2019 trabalhoPOO. All rights reserved.
//

#ifndef ExceptionClass_hpp
#define ExceptionClass_hpp

#include <stdio.h>

class ExceptionClass {
    char * message;
public:
    ExceptionClass(int index);
    const char *what() const {return message;};
};

#endif /* ExceptionClass_hpp */

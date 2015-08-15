//
//  main.cpp
//  DungeonMaker
//
//  Created by Eiichi Takebuchi on 2015/08/14.
//  Copyright (c) 2015年 Eiichi Takebuchi. All rights reserved.
//

#include <iostream>
#include "Section.hpp"

void main()
{
    dungeon::Section section(40, 30);
    
    int a = section.CheckPoint(dungeon::Point(0, 0));
    
    printf("%d", a);
}
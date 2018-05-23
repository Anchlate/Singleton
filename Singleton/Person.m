//
//  Person.m
//  Singleton
//
//  Created by apple on 2018/5/23.
//  Copyright © 2018年 Anchlate. All rights reserved.
//

#import "Person.h"

static id _instance;

@implementation Person

+ (id)allocWithZone:(struct _NSZone *)zone {
    
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _instance = [super allocWithZone:zone];
    });
    
    return _instance;
}

+ (id)sharePerson {
    
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _instance = [[self alloc]init];
    });
    return _instance;
}

- (id)copyWithZone:(NSZone *)zone {
    return _instance;
}

/*
- (oneway void)release {}

- (id)autorelease { return _instance; }

- (id)retain { return _instance; }

- (NSInteger)retainCount { return 1; }
*/


@end

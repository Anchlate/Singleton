//
//  ANSingletion.h
//  Singleton
//
//  Created by apple on 2018/5/23.
//  Copyright © 2018年 Anchlate. All rights reserved.
//

#ifndef ANSingletion_h
#define ANSingletion_h

// .h 文件
#define ANSingletonH(name) + (instancetype)share##name;


// .m 文件

// ARC
#if __has_feature(objc_arc)

#define ANSingletonM(name) \
static id _instance; \
\
+ (id)allocWithZone:(struct _NSZone *)zone { \
    static dispatch_once_t onceToken; \
    dispatch_once(&onceToken, ^{ \
        _instance = [super allocWithZone:zone]; \
    }); \
    return _instance; \
} \
\
+ (id)share##name { \
    static dispatch_once_t onceToken; \
    dispatch_once(&onceToken, ^{ \
        _instance = [[self alloc]init]; \
    }); \
    return _instance; \
} \
\
- (id)copyWithZone:(NSZone *)zone { \
    return _instance; \
}

// MRC
#else

#define ANsingletionM(name) \
static id _instance; \
\
+ (id)allocWithZone:(struct _NSZone *)zone { \
    static dispatch_once_t onceToken; \
    dispatch_once(&onceToken, ^{ \
        _instance = [super allocWithZone:zone]; \
    }); \
    return _instance; \
} \
\
+ (id)share##name { \
    static dispatch_once_t onceToken; \
    dispatch_once(&onceToken, ^{ \
        _instance = [[self alloc]init]; \
    }); \
    return _instance; \
} \
\
- (id)copyWithZone:(NSZone *)zone { \
    return _instance; \
} \
\
- (oneway void)release {} \
\
- (id)autorelease { return _instance; } \
\
- (id)retain { return _instance; } \
\
- (NSInteger)retainCount { return 1; }


#endif


#endif /* ANSingletion_h */

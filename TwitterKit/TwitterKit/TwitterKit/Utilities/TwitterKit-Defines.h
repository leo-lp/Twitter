//
//  Prefix header
//
//  The contents of this file are implicitly included at the beginning of every source file.
//

#import <Foundation/Foundation.h>
#import "TWTRDefines.h"

#define IS_UIKIT_AVAILABLE (TARGET_OS_IOS || TARGET_OS_TV)

#ifndef NS_DESIGNATED_INITIALIZER
    #if __has_attribute(objc_designated_initializer)
        #define NS_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
    #else
        #define NS_DESIGNATED_INITIALIZER
    #endif
#endif

#import "EXTKeyPathCoding.h"
#import "EXTScope.h"

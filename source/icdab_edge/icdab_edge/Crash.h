//
//  Crash.h
//  icdab_edge
//
//  Created by Faisal Memon on 09/09/2018.
//  Copyright © 2018 Faisal Memon. All rights reserved.
//

#ifndef Crash_h
#define Crash_h

#import <Foundation/Foundation.h>

@interface Crash : NSObject

- (void)corruptMalloc;
- (void)overshootAllocated;
- (void)useAfterFree;
- (void)uninitializedMemory;
- (void)overReleasedObject;

@end

#endif /* Crash_h */

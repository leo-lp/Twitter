/*
 * Copyright (C) 2017 Twitter, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#import "TWTRTweetRepository.h"
#import "TWTRAPIConstants.h"
#import "TWTRAPIServiceConfig.h"
#import "TWTRAPIServiceConfigRegistry.h"
#import "TWTRAssertionMacros.h"
#import "TWTRConstants.h"
#import "TWTRSessionStore.h"
#import "TWTRAPIClient.h"
#import "TWTRAPIConstantsStatus.h"
#import "TWTRStore.h"
#import "TWTRSubscriber.h"
#import "TWTRSubscription.h"
#import "TWTRTweet.h"
#import "TWTRTweetCache.h"
#import "TWTRTwitter.h"
#import "TWTRUser.h"
#import "TwitterKit-Defines.h"

typedef void (^TWTRTweetCacheLoadTweetIDsCompletion)(NSArray *cachedTweets, NSArray *cacheMissTweetIDs);
static NSString *const TWTRTweetCachePath = @"cache/tweets";
static const NSUInteger MB = 1048576;
static const NSUInteger TWTRTweetCacheMaxSize = 5 * MB;

@interface TWTRTweetRepository ()

@property (nonatomic, strong) id<TWTRTweetCache> cache;

@end

@implementation TWTRTweetRepository

#pragma mark - Singleton Accessor

+ (instancetype)sharedInstance
{
    static TWTRTweetRepository *sharedInstance;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        NSString *path = [self cacheDirectoryPath];
        TWTRTweetCache *cache = [[TWTRTweetCache alloc] initWithPath:path maxSize:TWTRTweetCacheMaxSize];
        sharedInstance = [[TWTRTweetRepository alloc] initWithCache:cache];
    });

    return sharedInstance;
}

#pragma mark - Init

- (instancetype)initWithCache:(id<TWTRTweetCache>)cache
{
    self = [super init];

    if (self) {
        _cache = cache;
    }

    return self;
}

#pragma mark - Tweet API Methods

- (void)cacheTweet:(TWTRTweet *)tweet
{
    [self cacheTweet:tweet perspective:tweet.perspectivalUserID];
}

- (void)cacheTweet:(TWTRTweet *)tweet perspective:(NSString *)perspective
{
    [self.cache storeTweet:tweet perspective:perspective];
    [[TWTRStore sharedInstance] notifySubscribersOfChangesToObject:tweet withID:tweet.tweetID];
}

#pragma mark - Helpers

+ (NSString *)cacheDirectoryPath
{
    NSString *cacheDir = [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject];
    NSString *tweetCacheFullPath = [cacheDir stringByAppendingPathComponent:TWTRTweetCachePath];

    return tweetCacheFullPath;
}

@end

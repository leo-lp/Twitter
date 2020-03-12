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

/**
 This header is private to the Twitter Kit SDK and not exposed for public SDK consumption
 */

#import "TWTRAPIClient.h"

@class TWTRAPIClient;
@class TWTRTweet;

NS_ASSUME_NONNULL_BEGIN

typedef void (^TWTRTweetRepoSingleTweetCompletion)(TWTRTweet *_Nullable tweet, NSError *_Nullable error);

/**
 Private class that encapsulates the business logic of fetching Tweets and caching them
 */
@interface TWTRTweetRepository : NSObject
/**
 *  Shared Tweet repository.
 *
 *  @return The single instance of a TWTRTweetRepository
 */
+ (instancetype)sharedInstance;

#pragma mark - Tweet API Methods

/**
 *  Cache a single Tweet to disk. Uses the .perspectivalUserId of the tweet to store
 *  each Tweet with respect to the user that loaded it.
 *
 *  @param tweet The TWTRTweet model object to cache.
 */
- (void)cacheTweet:(TWTRTweet *)tweet;

/**
 *  Cache a single Tweet to disk from a given perspective.
 *
 *  @param tweet       The TWTRTweet model object to cache.
 *  @param perspective The userID associated with this tweet.
 */
- (void)cacheTweet:(TWTRTweet *)tweet perspective:(NSString *)perspective;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

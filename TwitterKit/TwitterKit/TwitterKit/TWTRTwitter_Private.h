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

#import "TWTRNetworking.h"
#import "TWTRUserSessionVerifier.h"
#import "TWTRImageLoader.h"
#import "TWTRTwitter.h"

@class TWTRAuthClient;
@class TWTRTweetRepository;
@class TWTRUserSessionVerifier;
@protocol TWTRAPIServiceConfig;

@interface TWTRTwitter () <TWTRUserSessionVerifierDelegate>

@property (nonatomic) NSDictionary *kitInfo;
@property (nonatomic, readonly) TWTRUserSessionVerifier *userSessionVerifier;
@property (nonatomic, readonly, getter=isInitialized) BOOL initialized;
@property (nonatomic) TWTRAuthConfig *authConfig;

@property (nonatomic, readonly) TWTRImageLoader *imageLoader;

- (void)userSessionVerifierNeedsSessionVerification:(TWTRUserSessionVerifier *)userSessionVerifier;

@end

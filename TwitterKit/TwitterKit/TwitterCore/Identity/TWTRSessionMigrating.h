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
 This header is private to the Twitter Core SDK and not exposed for public SDK consumption
 */

#import "TWTRSessionStore.h"

@protocol TWTRSessionMigrating <NSObject>

/**
 * Specifies that the migrator should migrate any existing sessions into the given store.
 *
 * @param store the store to migrate sessions to
 * @param removeOnSuccess if the migrator should remove the sessions on successful migration.
 */
- (void)runMigrationWithDestination:(id<TWTRSessionStore>)store removeOnSuccess:(BOOL)removeOnSuccess;

@end

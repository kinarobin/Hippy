/*!
 * iOS SDK
 *
 * Tencent is pleased to support the open source community by making
 * Hippy available.
 *
 * Copyright (C) 2019 THL A29 Limited, a Tencent company.
 * All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import <Foundation/Foundation.h>
#import "HippyDevInfo.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(unsigned int, HippyDevWebSocketState) {
    DevWebSocketState_CONNECTING = 0,
    DevWebSocketState_OPEN = 1,
    DevWebSocketState_CLOSING = 2,
    DevWebSocketState_CLOSED = 3,
};

@class HippyDevWebSocketClient;

@protocol HippyDevClientProtocol <NSObject>

@optional
- (void)devClientDidConnect:(HippyDevWebSocketClient *)devClient;
- (void)devClient:(HippyDevWebSocketClient *)devClient didFailWithError:(NSError *)error;
- (void)devClientDidClose:(HippyDevWebSocketClient *)devClient;
- (void)devClient:(HippyDevWebSocketClient *)devClient didReceiveMessage:(NSString *)message;

@end

@interface HippyDevWebSocketClient : NSObject

@property(nonatomic, readonly)NSURL *devURL;
@property(nonatomic, weak)id<HippyDevClientProtocol> delegate;
@property(nonatomic, readonly)HippyDevWebSocketState state;

- (instancetype)initWithDevInfo:(HippyDevInfo *)devInfo contextName:(NSString *)contextName;

- (void)sendData:(id)data;

- (void)closeWithCode:(NSInteger)code reason:(NSString *)reason;

@end

NS_ASSUME_NONNULL_END

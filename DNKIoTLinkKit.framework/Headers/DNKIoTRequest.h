//
//  DNKIoTRequest.h
//  NewSmart
//
//  Created by 陈群 on 2022/4/1.
//

#import <Foundation/Foundation.h>
#import <DNKIoTLinkKit/DNKIoTLinkKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol DNKIoTRequestAccessory <NSObject>

@optional
/// 请求发送前调用
- (void)requestWillStart:(DNKIoTRequest *)request;
/// 请求即将结束调用
- (void)requestWillStop:(DNKIoTRequest *)request;
/// 请求已经结束调用
- (void)requestDidStop:(DNKIoTRequest *)request;

@end

@interface DNKIoTRequest : NSObject
/// 由IoTService 里设置fromDev和toDev
@property (nonatomic, copy) NSString *fromDev;
@property (nonatomic, copy) NSString *toDev;
@property (nonatomic, copy) NSString *originSendCmd;
@property (nonatomic, strong) NSDictionary *cmdData;
@property (nonatomic, copy, readonly) NSString *uuid; 
/// 指令行为
@property (nonatomic, copy) NSString *action;

// 通过局域网发送，默认NO，外网和局域网都会发送；YES：优先通过MQTT发送，其次UDP
@property (nonatomic) BOOL onlyLAN;  
/// communicateMode为UDP通信时，指定dupIP发起单播，不指定使用组播通信
@property (nonatomic, copy) NSString *udpIP;
@property (nonatomic) NSInteger udpPort;
/// 默认6s
@property (nonatomic) NSTimeInterval timeout;
/// 发出指令的的对象.为nil时，不会结果回调
@property (nonatomic, weak) id owner;
/// 指令执行回调
@property (nonatomic, copy) IoTResultBlock resultBlock;
/// 请求响应结果
@property (nonatomic, strong, readonly, nullable) DNKIoTResponse *response;

/// 指令执行回调
@property (nonatomic, strong, nullable) NSMutableArray<id<DNKIoTRequestAccessory>> *requestAccessories;
/// 添加请求配件
- (void)addAccessory:(id<DNKIoTRequestAccessory>)accessory;
/// 设置resultBlock
- (DNKIoTRequest *)completetionBlock:(IoTResultBlock)block;
/// 开始请求，未设置owner不会执行resultBlock.
/// 通过该方式，会为数据包裹一层fromDev,toDev
- (DNKIoTRequest *)start;
- (DNKIoTRequest *)start:(nullable id)owner;

/// 开始请求，未设置owner不会执行resultBlock.
/// 通过该方式，不会为数据包裹一层fromDev,toDev
- (DNKIoTRequest *)startForUDP;
/// 停止请求
- (void)stop;

@end

NS_ASSUME_NONNULL_END

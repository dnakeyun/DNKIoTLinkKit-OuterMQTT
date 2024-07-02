//
//  DNKIoTService.h
//  NewSmart
//
//  Created by 陈群 on 2022/4/1.
//
 
#import <DNKIoTLinkKit/DNKIoTLinkKit.h>

@class DNKIoTConfig;
NS_ASSUME_NONNULL_BEGIN
// 网关主动推送的数据(mainThread)
FOUNDATION_EXPORT NSNotificationName const DNKActiveGateWayPushNotification;
static NSString * const BroadcastAddressIP = @"255.255.255.255";
/// 指令请求和响应管理
@interface DNKIoTService : NSObject
/// 退出登录的时候 手动置空 防止 死循环
@property (copy, nonatomic, nullable) void(^connectStateChangeBlock)(DNKIoTConnectState state, NSError *error);
/// MQTT建立成功后才会有值
@property (nonatomic, readonly, copy) NSString *gatewayIp;
@property (readonly, getter=isLAN, assign, nonatomic) BOOL LAN;
/// YES: 连接MQTT   NO：未连接MQTT
@property (nonatomic, assign, readonly) BOOL connectedMQTT;
@property (nonatomic, strong, readonly) DNKGatewayModel *mainGwInfoModel;
/// 是否启动IoT
@property (nonatomic, assign, readonly) BOOL startupFlag;

+ (DNKIoTService *)sharedService;

/// 更新config信息。在IoT启动后，会根据前后config差异，从而在内部判断是否重启IoT
/// @param iotConfig iotConfig
- (void)updateIoTConfig:(nonnull DNKIoTConfig *)iotConfig;

/// 启动IoT通讯
/// @param ioTConfig 配置
/// @param resultBlock 启动结果
- (void)startUpWithConfig:(DNKIoTConfig *)ioTConfig resultBlock:(nullable IoTBoolResult)resultBlock;
/// 发送request,并将数据包裹到fromDev、toDev内
- (void)addIoTRequest:(DNKIoTRequest *)iotRequest;
/// 发送request,不会将数据包裹到fromDev、toDev内
- (void)addUdpRequest:(DNKIoTRequest *)request;
/// 移除指定的request
- (void)removeRequestByCmdUuid:(NSString *)cmdUuid;
/// 移除所有待响应的request
- (void)removeAllRequest;
/// 关闭IoT通信
- (void)destroyResult:(nullable IoTBoolResult)resultBlock;

- (NSString *)ioTStateMessage;

@end

NS_ASSUME_NONNULL_END

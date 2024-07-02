//
//  DNKIoTConfig.h
//  NewSmart
//
//  Created by 陈群 on 2022/4/2.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 mqtt长连接通道配置信息
 */
@interface DNKIoTConfig : NSObject

/// 用户IoT三元组 iotProductKey
@property (nonatomic, copy) NSString *userKeyIoT;
/// 用户IoT三元组 iotDeviceName
@property (nonatomic, copy) NSString *userNameIoT;
/// 用户IoT三元组 iotDeviceSecret
@property (nonatomic, copy) NSString *userSecretIoT;
/// 设备IoT三元组 iotProductKey
@property (nonatomic, copy) NSString *deviceKeyIoT;
/// 设备IoT三元组 iotDeviceName
@property (nonatomic, copy) NSString *deviceNameIoT;
/// 设备IoT三元组 iotDeviceSecret
@property (nonatomic, copy) NSString *deviceSecretIoT;
/// 仅启动局域网通信，默认NO
@property (nonatomic) BOOL onlyLAN;

@property (nonatomic, copy) NSString *connectIP;
@property (nonatomic) int connectPort;

@end 
NS_ASSUME_NONNULL_END

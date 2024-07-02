//
//  DNKGatewayModel.h
//  NewSmart
//
//  Created by 陈群 on 2022/6/13.
//

#import <Foundation/Foundation.h> 
NS_ASSUME_NONNULL_BEGIN

@interface DNKGatewayModel : NSObject
/// zigbee协调器的版本信息
@property (nonatomic,  copy) NSString *coorVersion;
/// cpu类型 10: 网关，其他标准网关
@property (nonatomic) NSInteger cpu;
/// 本机dbus udp接收端口
@property (nonatomic) NSInteger dbusPort;
/// 手机APP的IOT设备名称
@property (nonatomic,  copy) NSString *devIotName;
/// 取值范围：0-智能网关
@property (nonatomic) NSInteger devType;
/// 网关的IOT帐号
@property (nonatomic,  copy) NSString *gwIotName;
/// 手机APP的IOT产品KEY
@property (nonatomic,  copy) NSString *gwIotProductKey;
/// 网关的IOT帐号的密钥
@property (nonatomic,  copy) NSString *gwIotSecret;
/// IOT服务器的端口
@property (nonatomic) NSInteger iotPort;
/// IOT服务器的 url
@property (nonatomic,  copy) NSString *iotUrl;
/// 网关ip地址
@property (nonatomic,  copy) NSString *ip;
/// 具体设备类型
@property (nonatomic) NSInteger limit;
/// mac地址
@property (nonatomic,  copy) NSString *mac;
/// 本机mqtt接收端口
@property (nonatomic) NSInteger lmqttPort;
/// sdk包的版本信息，eg: Z-GT-S01_V3.0.1_20220728
@property (nonatomic,  copy) NSString *sdkVersion;
/// 单片机版本号
@property (nonatomic,  copy) NSString *mcuVersion;
/// 3.0.1 (自定义，非网关返回数据)
@property (nonatomic, copy, readonly) NSString *shortVerion;
/// 网关SN码
@property (nonatomic,  copy) NSString *udid;
/// 本机udp接收端口
@property (nonatomic) NSInteger udpPort;
@property (nonatomic) BOOL WLAN;
@property (nonatomic,  copy) NSString *modelId;
/// 网关类型，eg：["zigbee", "can"]
@property (nonatomic, strong) NSArray<NSString *> *mode;
/// 是否是主网关，1 - 主网关，不可以被级联，0 - 可以被级联
@property (nonatomic) NSInteger master;

/// 是否是从网关，1 - 已被级联，不可以再级联， 0 - 可以被级联
@property (nonatomic) NSInteger slave;
@end

NS_ASSUME_NONNULL_END

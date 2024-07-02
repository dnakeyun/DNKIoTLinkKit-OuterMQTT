//
//  DNKIoTUtils.h
//  smarthome
//
//  Created by 陈群 on 2021/8/24.
//  Copyright © 2021 dnake. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


/// 指定版本比较结果
typedef NS_ENUM(NSInteger, GWComparisonResult) {
    GWComparisonOfUnknow,  /// 比较结果未知，即未获取到当前网关版本
    GWComparisonOfGreater, /// 大于指定版本
    GWComparisonOfSame,    /// 等于指定版本
    GWComparisonOfLess     /// 小于指定版本
};

typedef NS_ENUM (NSInteger, DNKIoTMode) {
    DNKIoTModeOfNone = 0,
    /// 阿里（外网）
    DNKIoTModeOfAli = 1 << 0,
    /// 局域网UDP
    DNKIoTModeOfUDP = 1 << 1,
    /// 局域网MQTT
    DNKIoTModeOfMQTT = 1 << 2,
    /// 连接外部搭建的MQTT
    DNKIoTModeOfOuterMQTT = 1 << 3,
};

@interface DNKIoTUtils : NSObject
/// 网关响应的错误信息
+ (NSString *)errorMsgWithGatewayErrCode:(NSInteger)errCode;
/// 重置Wi-Fi名称，默认为“none”
+ (NSString *)resetWiFiSsid;
/// 重置Wi-Fi密码，默认为123456
+ (NSString *)resetWiFiPsk;
/// 网关热点名称
+ (NSString *)gatewayHotspot:(NSString *)gwUdid;
/// 拼接网关的IOT帐号
/// @return g_gwUdid账号
+ (NSString *)gatewayName:(NSString *)gwUdid;
/// 返回网关的IOT帐号前缀
+ (NSString *)gwIoTNamePrefix;
/// 比较指定网关与当前网关版本
+ (GWComparisonResult)compareVersion:(NSString *)version;
#pragma mark - UDP 通信方式 加密 和 解密
/// 数据加密
+ (NSData *)encrytData:(NSData *)data;
/// 数据解密
+ (NSData *)decryptData:(NSData *)data;
/// 加密后的数据转字典
+ (NSDictionary *)dictionaryWithEncrytData:(NSData *)encrytData;
/// 字典转JSON
+ (NSString *)dataJSONWithData:(NSDictionary *)dictionary;
@end

NS_ASSUME_NONNULL_END

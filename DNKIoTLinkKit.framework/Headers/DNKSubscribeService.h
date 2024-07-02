//
//  DNKSubscribeService.h
//  NewSmart
//
//  Created by 陈群 on 2022/7/28.
//

#import <Foundation/Foundation.h>

#pragma mark - 网关主动推送的消息类型
typedef  NSString * _Nonnull GWPushCmtKey  NS_STRING_ENUM;
/// （网关）主动推上报的设备状态
FOUNDATION_EXPORT GWPushCmtKey const  GWPushCmtDevStatKey;
/// （网关）主动推设备信息
FOUNDATION_EXPORT GWPushCmtKey const GWPushCmtDevInfoKey;
/// （网关）主动推上报的设备报警信息
FOUNDATION_EXPORT GWPushCmtKey const GWPushCmtDevAlarmKey;
/// （服务端）主动推的信息
FOUNDATION_EXPORT GWPushCmtKey const GWPushCmtCloudKey;
/// （网关）主动推送子设备升级进度
FOUNDATION_EXPORT GWPushCmtKey const GWPushCmtGwInfoKey;


NS_ASSUME_NONNULL_BEGIN


/// 订阅网关/服务端主动推送的数据
@interface DNKIoTSubscribe : NSObject
/// 订阅期间就会一直收到数据(当subscriber为nil时，会移除订阅列表)
@property (weak, nonatomic) id subscriber;
/// 收到订阅数据会执行block（Main Thread）
@property (copy, nonatomic) void(^subscribeBlock)(NSDictionary *data);
/// 要订阅的数据，订阅的内容与网关推送的数据类型一致时才会响应
@property (strong, nonatomic) NSSet<GWPushCmtKey> *subscribeList; 

/// 便捷方法，构建DNKIoTSubscribe
/// - Parameters:
///   - subscriber: 订阅者
///   - subscribeList: 订阅内容
///   - subscribeBlock: 收到订阅数据会执行block Main Thread）
+ (instancetype)subscriber:(id)subscriber
             subscribeList:(NSArray<GWPushCmtKey> *)subscribeList
            subscribeBlock:(void(^)(NSDictionary *data))subscribeBlock;
/// 便捷方法，构建DNKIoTSubscribe，并调用addIoTSubscribe:
/// - Parameters:
///   - subscriber: 订阅者
///   - subscribeList: 订阅内容
///   - subscribeBlock: 收到订阅数据会执行block Main Thread）
+ (instancetype)addSubscriber:(id)subscriber
                subscribeList:(NSArray<GWPushCmtKey> *)subscribeList
               subscribeBlock:(void(^)(NSDictionary *data))subscribeBlock;
@end

/// 管理订阅者
@interface DNKSubscribeService: NSObject
/// 单例
+ (DNKSubscribeService *)service;
/// 添加订阅
- (void)addIoTSubscribe:(DNKIoTSubscribe *)subscription;
/// 删除订阅
- (void)removeSubscribe:(DNKIoTSubscribe *)subscription;
/// 删除订阅者里的所有订阅
- (void)removeSubscriber:(id)subscriber;

@end

NS_ASSUME_NONNULL_END

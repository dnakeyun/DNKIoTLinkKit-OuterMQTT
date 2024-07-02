//
//  DNKIoTResponse.h
//  NewSmart
//
//  Created by 陈群 on 2022/4/2.
//

#import <Foundation/Foundation.h>
#import <DNKIoTLinkKit/DNKIoTLinkKit.h>

NS_ASSUME_NONNULL_BEGIN
@class IoTError;
@interface DNKIoTResponse : NSObject
/// 执行结果，YES：成功 ，NO：失败
@property (assign, nonatomic) BOOL result;
/// result为YES时，值为nil，否则不为nil
@property (strong, nonatomic) NSError *error;
/// result为YES时，有值，为NO 时 针对主动处理的错误值为nil,例如主动判断超时、g账号信息不存在、用户信息不存在.网关返回的错误,一般有值
@property (strong, nonatomic) NSDictionary *data;

@end

@interface IoTError : NSObject
@property (assign, readonly, nonatomic) DNKIotErrorCode errCode;
@property (copy, readonly, nonatomic) NSString *errorMsg;

+ (instancetype)errWithCode:(NSInteger)code errorMsg:(NSString *)description;

@end

NS_ASSUME_NONNULL_END

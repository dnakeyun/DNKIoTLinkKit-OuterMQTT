//
//  DNKIoTKitDefine.h
//  smarthome
//
//  Created by 陈群 on 2020/11/27.
//  Copyright © 2020 dnake. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef DNKIoTKitDefine_h
#define DNKIoTKitDefine_h

@class DNKIoTRequest, DNKIoTResponse;
 
typedef NS_ENUM (NSInteger, DNKIoTConnectState){
    DNKIoTConnectStateConnected = 1,
    DNKIoTConnectStateDisconnected = 2,
    DNKIoTConnectStateConnecting = 3,
    DNKIoTConnectStateFailure = 4,
};
typedef NS_ENUM(NSInteger, DNKTopicType) {
    /// get 获取网关主动响应的数据
    DNKTopicActivePushType = 1,
    /// update 获取APP控制，网关响应的数据
    DNKTopicRespondType = 2,
};


typedef NS_ENUM(NSInteger, DNKIotErrorCode) {
    /// 未知错误
    IoTUnknownErr = 101,
    /// 协议格式错误
    IoTProtocolFormatErr = 102,
    /// 传递参数错误
    IoTParamErr = 103,
    /// 操作对象不存在
    IoTNotExistErr = 104,
    /// 操作对象已存在
    IoTExistsErr = 105,
    /// 未准备就绪
    IoTNotReadyErr = 106,
    /// 无操作权限
    IoTNoPermissionsErr = 107,
    /// 设备处于离线状态
    IoTDevOfflineErr = 108,
    /// 操作超时(网关与设备端之间出现问题，转译成设备离线或网关响应超时)
    IoTTimeoutErr = 109,
    /// 设备类型错误
    IoTDevTypeErr = 110,
    /// 设备已存在
    IoTDevExistErr = 111,
    IoT_ZIGBEE_COORD_OFFLINE = 112,        //网关的zigbee协调器不在线
    IoT_ZIGBEE_NO_EP_RSP = 113,        //入网的zigbee设备无端点响应
    IoT_ZIGBEE_NO_EP_DESC_RSP = 114,        //入网的zigbee设备无端点描述符响应
    IoT_ZIGBEE_NO_TEMP_CFG_RSP = 115,        //入网时配置温湿度传感器的温度属性无响应
    IoT_ZIGBEE_NO_HUMI_CFG_RSP = 116,        //入网时配置温湿度传感器的湿度属性无响应
    IoT_ZIGBEE_NO_POWER_CFG_RSP = 117,        //入网时配置温湿度传感器的电量属性无响应
    IoT_REPET_OPERATION = 118,        //重复操作，如当前是回家场景，但是再次收到回家场景时会提示重复操作
    /// Udid校验失败
    DNKVerifyUdidFailure = 124,
    /// 文件已存在
    DNKFileNotExist  = 128,
    /// 文件已存在
    DNKFileExist  = 129,
#pragma mark - 自定义错误码
    /// 请先绑定网关
    DNKNoBindingGateway  = 10000,
    /// APP未连接Wi-Fi，无法在局域网和网关通信。
    DNKCommunicateFailure  = 10001,
    /// 用户三元组信息不存在
    DNKUserIoTNotExist  = 10002,
    /// 操作超时 （App 与网关之间的通讯出现问题）
    DNKRequestTimeout = 10099,
    /// 指令发送失败
    DNKRequestSendFailure = 10100,
};
typedef void (^IoTBoolResult)(BOOL result, NSError * _Nullable error);
typedef void (^IoTResultBlock)(DNKIoTRequest * _Nonnull request, DNKIoTResponse * _Nonnull response);


#endif /* DNKIoTKitDefine_h */

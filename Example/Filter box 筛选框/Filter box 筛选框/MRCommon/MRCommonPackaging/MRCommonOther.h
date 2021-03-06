//
//  MRCommonOther.h
//  test
//
//  Created by 刘入徵 on 2017/4/15.
//  Copyright © 2017年 Mix_Reality. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef void(^OKBlock)();
typedef void(^CancleBlock)();
typedef void(^DelayBlock)();

// 判断是否有网的 enum  If there is a network of judgment
typedef NS_ENUM(NSInteger, CommonOtherNetWorkType){

    CommonOtherTypeNoNetwork    =  0,   // 没有网  No network
    CommonOtherType3G           =  1,   // 3G 网  The 3g network
    CommonOtherTypeWifi         =  2    // wifi   Wifi network
};

// 判断号码状态 enum Determine number state
typedef NS_ENUM(NSInteger, CommonOtherThingType) {

    CommonOtherTypeCallPhone    =  0,    // 打电话             Make a phone call
    CommonOtherTypeSendMessage  =  1,    // 发短信             texting
    CommonOtherTypeSendEmail    =  2,    // 发邮件             email
    CommonOtherTypeJumpAppStore =  3     // 跳转到 appStore    Jump to appStore
};

// DoubleAlert 的 enum
typedef NS_ENUM(NSInteger, CommonOtherDoubleAlertType){

    CommonOtherCancelAndOK      = 1,     // 取消和确定 CancelAndOK
    CommonOtherCancelAndGo      = 2,     // 取消和前往 CancelAndGo
    CommonOtherCancelAndAdd     = 3      // 取消和添加 CancelAndAdd
};



@interface MRCommonOther : NSObject

/**
 判断网络状态  To determine the network status
 TypeNoNetwork: 没有网   / Type3G: 3G    / TypeWifi Wifi
 */
+ (CommonOtherNetWorkType)checkNetwork;

/**
 判断号码状态 Determine number state
 TypeCallPhone: 打电话  TypeSendMessage: 发短信  TypeSendEmail: 发邮件  TypeJumpAppStore: 跳转到 AppStore
 */
+ (void)num:(NSString *)number andType:(CommonOtherThingType)type;

/**
 反序列化 deserialization
 */
+(NSDictionary *)jsonDictionarBystring:(NSString *)message;

/**
 获取 根控制器 To obtain the root controller
 */
+ (UIViewController *)getRootVC;

/**
 获取 view 所在的控制器 Get a view of the controller
 @param view 视图
 */
+ (UIViewController *)getViewControllerByView:(UIView *)view;

/**
 获取文件大小 Access to the file size
 */
+ (long long)fileSizeAtPath:(NSString *)filePath;

/**
 *  获取 path 路径文件夹的大小                Get the size of the folder path path
 *  @param path 要获取大小的文件夹全路径       The full path to get the size of the folder
 *  @return 返回 path 路径文件夹的大小        Return the size of the folder path path
 */
+ (NSString *)getCacheSizeWithFilePath:(NSString *)path;

/**
 *  清除 path 路径文件夹的缓存            To clear the path cache folder
 *  @param path  要清除缓存的文件夹全路径  The full path to clear the cache folder
 *  @return 是否清除成功                 Whether to clear success
 */
+ (BOOL)clearCacheWithFilePath:(NSString *)path;

/**
 MD5 32 位加密 MD5 32-bit encryption
 */
+ (NSString *)md5With32:(NSString *)str;

/**
 32位 MD5 大写
 */
+ (NSString *)md5With32Big:(NSString *)str;

/**
 添加偏移量的加密 Add the offset of the encryption
 */
+ (NSString *)MD5WithPassWord:(NSString *)str;

/**
  创建一个 两选项的 alert, Create a two options alert
  CommonOtherCancelAndOK:  取消 确定
  CommonOtherCancelAndGo:  取消 前往
  CommonOtherCancelAndAdd: 取消 添加
 */
+ (void)alertWithTitle:(NSString *)title message:(NSString *)message type:(CommonOtherDoubleAlertType)type viewController:(UIViewController *)viewController OKBlock:(OKBlock)okBlock CancelBlock:(CancleBlock)cancelBlock;

/**
创建一个 单选项的 alert, Create a one option alert
 */
+ (void)alertSingleWithTitle:(NSString *)title message:(NSString *)message buttonName:(NSString *)name viewController:(UIViewController *)viewController OKBlock:(OKBlock)okBlock;

/**
 延时调用 Delay call
 */
+ (void)delayWithTime:(NSTimeInterval)time delayBlock:(DelayBlock)block;

@end

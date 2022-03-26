#import <Flutter/Flutter.h>
#import <CoreBluetooth/CoreBluetooth.h>

@interface PublicBlePlugin : NSObject<FlutterPlugin>
+ (void)registerWithRegistrar:(NSObject<FlutterPluginRegistrar>*)registrar;

@end

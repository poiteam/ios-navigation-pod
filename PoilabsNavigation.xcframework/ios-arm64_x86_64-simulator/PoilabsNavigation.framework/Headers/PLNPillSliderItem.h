// CategoryItem.h
#import <UIKit/UIKit.h>

@interface PLNPillSliderItem : NSObject
@property (nonatomic, copy) NSString *title;
@property (nonatomic, strong, nullable) NSString *iconUrl;
+ (instancetype)itemWithTitle:(NSString *)title iconUrl:(NSString * _Nullable)iconUrl;
@end

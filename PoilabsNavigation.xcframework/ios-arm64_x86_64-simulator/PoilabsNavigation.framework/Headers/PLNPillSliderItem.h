// CategoryItem.h
#import <UIKit/UIKit.h>

@interface PLNPillSliderItem : NSObject
@property (nonatomic, copy) NSString *title;
@property (nonatomic, strong, nullable) NSString *iconUrl;
@property (nonatomic, strong, nullable) NSNumber *categoryId;
+ (instancetype)itemWithTitle:(NSString *)title iconUrl:(NSString * _Nullable)iconUrl;
+ (instancetype)itemWithTitle:(NSString *)title iconUrl:(NSString * _Nullable)iconUrl categoryId:(NSNumber * _Nullable)categoryId;
@end

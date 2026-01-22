#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, PLNRouteStepIconType) {
    PLNRouteStepIconTypeNone = 0,
    PLNRouteStepLocation,
    PLNRouteStepNoLocation,
    PLNRouteStepIconTypeDirect,
    PLNRouteStepIconTypeFloorChangeUp,
    PLNRouteStepIconTypeFloorChangeUpStairs,
    PLNRouteStepIconTypeFloorChangeUpElevator,
    PLNRouteStepIconTypeFloorChangeDown,
    PLNRouteStepIconTypeFloorChangeDownStairs,
    PLNRouteStepIconTypeFloorChangeDownElevator,
    PLNRouteStepIconTypeNoReturn,
    PLNRouteStepIconTypeRight,
    PLNRouteStepIconTypeLeft,
    PLNRouteStepIconTypeFinish
};

@interface PLNRouteInfoDetailView : UIView

@property (nonatomic, assign) BOOL isLoaded;

- (instancetype)initWithTitle:(NSString *)title
                     andImage:(NSString *)image;

- (void)configureRouteSteps:(NSArray<NSDictionary *> *)stepsInfo maxHeight:(CGFloat)maxHeight;
-(void)scrollToFirst;
- (void)refreshTable;
@end

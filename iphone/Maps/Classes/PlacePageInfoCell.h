
#import <UIKit/UIKit.h>
#include "../../geometry/point2d.hpp"
#import "SelectedColorView.h"
#import "SmallCompassView.h"

@class PlacePageInfoCell;
@protocol PlacePageInfoCellDelegate <NSObject>

- (void)infoCellDidPressCoordinates:(PlacePageInfoCell *)cell withGestureRecognizer:(UIGestureRecognizer *)gestureRecognizer;
- (void)infoCellDidPressAddress:(PlacePageInfoCell *)cell withGestureRecognizer:(UIGestureRecognizer *)gestureRecognizer;
- (void)infoCellDidPressColorSelector:(PlacePageInfoCell *)cell;

@end

@interface PlacePageInfoCell : UITableViewCell

+ (CGFloat)cellHeightWithAddress:(NSString *)address viewWidth:(CGFloat)viewWidth inMyPositionMode:(BOOL)myPositon;

- (void)setAddress:(NSString *)address pinPoint:(m2::PointD)point;
- (void)updateDistance;
- (void)updateCoordinates;

@property (nonatomic) UIColor * color;
@property (nonatomic) BOOL myPositionMode;

@property (nonatomic, readonly) UIImageView * separator;
@property (nonatomic, readonly) SelectedColorView * selectedColorView;
@property (nonatomic, readonly) SmallCompassView * compassView;

@property (nonatomic, weak) id <PlacePageInfoCellDelegate> delegate;

@end

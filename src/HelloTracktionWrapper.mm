//
//  HelloTracktionWrapper.mm
//  tracker
//
//  Created by Sercan Atlı on 24/03/2023.
//

#import "HelloTracktionWrapper.h"

#import "HelloTracktion.h"

@implementation HelloTracktionWrapper
- (NSString *) sayHello {
    HelloTracktion helloTracktion;
    std::string helloWorldMessage = helloTracktion.sayHello();
    return [NSString
            stringWithCString:helloWorldMessage.c_str()
            encoding:NSUTF8StringEncoding];
}
@end

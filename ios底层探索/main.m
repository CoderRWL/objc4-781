//
//  main.m
//  ios底层探索
//
//  Created by RWLi on 2020/9/10.
//

#import <Foundation/Foundation.h>
#import "Person.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"---");
        
        Person *p = [[Person alloc]init];
        
        NSLog(@"p=%p",p);
        
    }
    return 0;
}

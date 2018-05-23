//
//  ViewController.m
//  Singleton
//
//  Created by Anchlate Lee on 16/5/2.
//  Copyright © 2016年 Anchlate. All rights reserved.
//

#import "ViewController.h"
#import "Person.h"
#import "Student.h"


@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    Person *p0 = [Person sharePerson];
    Person *p1 = [Person sharePerson];
    NSLog(@"..%@\n%@\n", p0, p1);
    
    
    Student *s0 = [Student shareStudent];
    Student *s1 = [Student shareStudent];
    NSLog(@"..%@\n%@\n", s0, s1);
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end

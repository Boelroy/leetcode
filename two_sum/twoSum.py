#!/usr/bin/env python

def twoSum(nums, target):
    hashMap = {}
    for i in range(len(nums)):
        hashMap[nums[i]] = i
    for i in range(len(nums)):
        other = target - nums[i]
        if other in hashMap and hashMap[other] != i:
            return [i, hashMap[other]]

if __name__ == '__main__':
    print twoSum([0,2,1,3], 5)

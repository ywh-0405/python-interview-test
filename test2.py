####################################################
# test2.py 是对test1.py的升级
######################################################


import numpy as np

class conclude:
    def __init__(self,):
        
        pass
    def sum_numbers(self,nums):
            return nums.sum()
        
    def multiply_numbers(self,nums):
        return nums.prod()
def test1():
    print("请输入数据，空格分开：")
    nums = input().split()
    print("输入的数字是：",nums)
    nums = [float(i) for i in nums]
    nums = np.asarray(nums)
    c = conclude()
    print("输入的数字的和是：",c.sum_numbers(nums))
    print("输入的数字的积是：",c.multiply_numbers(nums))
    

if __name__ == '__main__':
    test1()

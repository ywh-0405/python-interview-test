######################################################################
# TEST1.PY
#设计一个类，类里面有两个函数，并不确定函数输入是float还是int，但是也不i影响追中输出结果
######################################################################


class conclude:
    def __init__(self,):
        
        pass
    def sum_numbers(self,nums):
        count_add = 0
        for i in nums:
            if type(i) == int or type(i) == float:
                pass
            else:
                raise ValueError("输入的参数必须是数字")
            count_add += i
        return count_add
        
    def multiply_numbers(self,nums):
        result = 1
        for i in nums:
            if type(i) == int or type(i) == float:
                pass
            else:
                raise ValueError("输入的参数必须是数字")
            result =  result * i 
        return result
def test1():
    print("请输入数据，空格分开：")
    nums = input().split()
    print("输入的数字是：",nums)
    nums = [float(i) for i in nums]
    c = conclude()
    print("输入的数字的和是：",c.sum_numbers(nums))
    print("输入的数字的积是：",c.multiply_numbers(nums))
    

if __name__ == '__main__':
    test1()

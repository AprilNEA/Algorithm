class Person:
    def __init__(self, name, age):
        self.full_name = name.upper()
        self.age = age
        self.next_year_age = age + 1

        self.love_count = 0
        self.love_time = 0

    def hello(self):
        print(f"你好, {self.full_name}, 你今年 {self.age}")

    def get_married(self, who):
        print(f"{self.full_name} 和 {who.full_name} 結婚了")

    def make_love(self, who, duration):
        print(f"{self.full_name} 和 {who.full_name} 做爱了, {duration} 秒")
        self.love_count += 1
        self.love_time += duration
        print(f"这是{self.full_name} 第 {self.love_count} 次做爱，一共做了{self.love_time}秒")


april = Person("april", 19)
april.hello()
cxx = Person("cxx", 20)
cxx.hello()
cxx.get_married(april)
cxx.make_love(april, 100000)
cxx.make_love(april, 103000)
cxx.make_love(april, 100400)
cxx.make_love(april, 100070)

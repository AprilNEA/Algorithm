from typing import List

class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        boxTypesLen = len(boxTypes)

        # 按照质量给boxTypes排序，使用冒泡排序 排降序
        for i in range(boxTypesLen):
            for j in range(1, boxTypesLen - i):
                if boxTypes[j - 1][1] < boxTypes[j][1]:
                    boxTypes[j - 1], boxTypes[j] = boxTypes[j], boxTypes[j - 1]

        print(boxTypes)

        maxUnits = 0

        leftTruckSizes = truckSize

        for box in boxTypes:
            numberOfBoxes, numberOfUnitsPerBox = box

            if leftTruckSizes - numberOfBoxes >= 0:
                leftTruckSizes -= numberOfBoxes
                maxUnits += numberOfBoxes * numberOfUnitsPerBox
            else:
                maxUnits += leftTruckSizes * numberOfUnitsPerBox
                break

        return maxUnits


if __name__ == '__main__':
    solution = Solution()

    maxiumUnits = solution.maximumUnits([[1, 3], [2, 2], [3, 1]], 4)
    print(maxiumUnits)

    maxiumUnits = solution.maximumUnits([[5, 10], [2, 5], [4, 7], [3, 9]], 10)
    print(maxiumUnits)

def how_many_min_food(foods, _min):
    cnt = 0
    for food in foods:
        if food == _min:
            cnt += 1
    return cnt

def dish_end(foods):
    for food in foods:
        if food > 0:
            return False
    return True

def solution(food_times, k):
    answer = 0

    next_food = 0
    origin_food_num = len(food_times)

    while k > 0:
        k -= 1
        food_times[next_food] -= 1
        if next_food < (origin_food_num-1):
            next_food += 1
        else:
            next_food = 0

        if dish_end(food_times):
            return -1
        while food_times[next_food] == 0:
            if next_food < (origin_food_num-1):
                next_food += 1
            else:
                next_food = 0
    answer = next_food + 1

    return answer
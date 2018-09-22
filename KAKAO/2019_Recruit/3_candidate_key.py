ban_list = []

def a_in_b(a,b):
    for i in a:
        if not i in b:
            return False
    return True

def get_answer(relation, selected, to_select):
    global ban_list
    if to_select == 0:
        # print(selected)
        _set = set()
        for ban in ban_list:
            if a_in_b(ban, selected):
                # print(ban_list)
                # print('{}=={}'.format(str(ban)[1:-1], str(selected)[1:-1]))
                return 0
        for row in relation:
            t = []
            for s in selected:
                t.append(row[s])
            _set.add(tuple(t))
        if len(_set) == len(relation):
            # print(_set)
            # print(str(selected)[1:-1])
            ban_list.append(tuple(selected))
            # print(ban_list)
            return 1
        else:
            return 0
    else:
        col_max = len(relation[0])-1
        if selected:
            _start = selected[-1]+1
        else:
            _start = 0
        if _start > col_max:
            return 0
        _count = 0
        for i in range(_start, col_max+1):
            selected.append(i)
            _count += get_answer(relation, selected, to_select-1)
            del selected[-1]
        return _count




def solution(relation):
    answer = 0
    col_len = len(relation[0])
    for i in range(1,col_len+1):
        answer += get_answer(relation, [], i)
    
    return answer


# rel = [["100", "ryan", "music", "2"], ["200", "apeach", "math", "2"], ["300", "tube", "computer", "3"], ["400", "con", "computer", "4"], ["500", "muzi", "music", "3"], ["600", "apeach", "music", "2"]]
# print(solution(rel))
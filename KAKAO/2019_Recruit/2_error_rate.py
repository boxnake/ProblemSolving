fail_rate = []

def get_fail_rate(input):
    return fail_rate[input]

def get_answer(inputs):
    ret = []
    ret.append(inputs[0])
    for input in inputs[1:]:
        idx = 0
        for i in range(len(ret)):
            if get_fail_rate(ret[i]) < get_fail_rate(input):
                idx = i
                break
            elif get_fail_rate(ret[i]) == get_fail_rate(input) and input < ret[i]:
                idx = i
                break
            idx += 1
        ret.insert(idx, input)
    return ret

def solution(N, stages):
    global fail_rate
    answer = []

    success_count = 0
    fail_rate = [0.0] * (N+1)

    for stage in stages:
        if stage == N+1:
            success_count += 1

    for n in range(N,0,-1):
        answer.append(n)
        current_count = 0
        for stage in stages:
            if stage == n:
                current_count += 1
        if success_count != 0 or current_count != 0:
            fail_rate[n] = (current_count)/(success_count+current_count)
        success_count += current_count
        # print('fail_rate[{}] = {}'.format(n,fail_rate[n]))
    
    answer = get_answer(answer)

    return answer


# print(solution(4, [4,4,4,4,4]))
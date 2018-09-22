def solution(record):
    answer = []
    msgs = []

    uid_uname = {}
    
    for rec in record:
        sp_rec = rec.split(' ')
        cmd = sp_rec[0]
        uid = sp_rec[1]
        if cmd != "Leave":
            uname = sp_rec[2]

        if cmd == "Enter":
            uid_uname[uid] = uname
            msgs.append("{}ENTER".format(uid))
        elif cmd == "Change":
            uid_uname[uid] = uname
        else:
            msgs.append("{}LEAVE".format(uid))
    
    for msg in msgs:
        uid = msg[:-5]
        cmd = msg[-5:]
        uname = uid_uname[uid]
        if cmd == "ENTER":
            ans = "{}님이 들어왔습니다.".format(uname)
        elif cmd == "LEAVE":
            ans = "{}님이 나갔습니다.".format(uname)
        answer.append(ans)

    return answer

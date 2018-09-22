removables = [ [[1,0],[1,1],[1,2]], [[1,0],[2,0],[2,-1]], [[1,0],[2,0],[2,1]], [[1,0],[1,-1],[1,-2]], [[1,0],[1,-1],[1,1]] ]
points = [[0,1],[0,2],[1,2],[1,0],[2,0],[1,1],[1,2],[2,-1],[2,1],[1,-1],[1,-2],[2,1]]

def is_removable(block_list):
    for removable in removables:
        

def remove_block(board, y, x):
    block_id = board[y][x]
    max_y = len(board)-1
    max_x = len(board[0])-1
    block_list = []

    for point in points:
        new_y = y+point[0]
        new_x = x+point[1]
        if new_y <= max_y and new_y >= 0 and new_x <= max_x and new_x >= 0 and board[new_y][new_x] == block_id:
            block_list.append((new_y, new_x))
    
    
    




def solution(board):
    answer = 0
    for y in range(len(board)):
        for x in range(len(board[0])):

    return answer

def solution(s):
    en = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine']
    answer = ''
    for idx,key in enumerate(en):
        if key in s:
            s = s.replace(key, str(idx))
        answer = s
    return int(answer)
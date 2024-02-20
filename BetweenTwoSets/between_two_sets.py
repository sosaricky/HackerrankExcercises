def between_two_sets(a: list,b: list)-> int:
    
    candidate_with_first_condition_ok: int = 0
    candidate_with_second_condition_ok: int = 0
    candidate_with_both_conditions_ok: int = 0
    candidates: list = [*range(max(a),max(b)+1)]
    
    for candidate in candidates:
        for number_from_a in a:
            if(candidate % number_from_a == 0):
                candidate_with_first_condition_ok += 1
            else:
                break
        for number_from_b in b:
            if(number_from_b % candidate == 0):
                candidate_with_second_condition_ok += 1    
            else:
                break
        if(candidate_with_first_condition_ok == len(a) and candidate_with_second_condition_ok == len(b)):
            candidate_with_both_conditions_ok += 1
        
        candidate_with_first_condition_ok  = 0
        candidate_with_second_condition_ok = 0

    return candidate_with_both_conditions_ok


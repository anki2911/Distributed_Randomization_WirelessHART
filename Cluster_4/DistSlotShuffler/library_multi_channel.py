import sys
sys.path.append('../SingleChannel/')

def Preprocess_Flow(FLOW,Flow_Multi):
    for i in range(len(FLOW)):
        Flow_Multi.append([])
    for i in range(len(FLOW)):
        for j in range(len(FLOW[i].flow)):
            #FLow no, Hop no, Link
            Flow_Multi[i].append(((i+1),(j+1),FLOW[i].flow[j]))
            #print Flow_Multi[i]

def Copy_Schedule(Slots):
    Temp_Sched = []
    for i in range(len(Slots)):
        Temp_Sched.append(Slots[i])
    return Temp_Sched
    
def extract_current_slot(F_Seq,lb,ub,f_id):
    i = lb
    while i <= ub:
        for j in range(F_Seq[i]):
            if F_Seq[i][j] == f_id:
                return i
        i += 1
    return -1
    
def get_slot_number(F_Seq,arr_time,comp_time,k,j):
    i = arr_time
    count = k + 1
    #print "K " + str(count)
    while i <= comp_time:
        L = F_Seq[i]
        for k in range(len(L)):
            #print "Slot no " + str(i)
            #print "FLow id " + str(j)
            #print "count " + str(count)
            if L[k] <> -1 and L[k] == j:
                count -= 1
                if count == 0:
                    return i
        i += 1 

def get_position(Slots,curr_slot,j):
    for num in range(len(Slots[curr_slot])):
        #print Slots[curr_slot][num][2]
        #print j
        if Slots[curr_slot][num][2] == j:
            curr_posn = num
            return num
    return -1

        
def find_link_curr_slot(L,j):
    #print L
    for i in range(len(L)):
        #print L[i][2]
        if L[i][2] == j:
            from_node = L[i][0]
            to_node = L[i][1]
    return (from_node,to_node)
 
def find_Edge_no(from_node,to_node,Edge):
    for i in range(len(Edge)):
        if Edge[i][0] == from_node and Edge[i][1] == to_node:
            return i
    return -1   

def check_flow_constraint_lower(Slots,curr_slot,sn1,i):
    to_be_shuffled_flow = Slots[sn1][i][2] 
    #print "to_be_shuffled_flow " + str(to_be_shuffled_flow)
    if to_be_shuffled_flow == "-":
        return 1
    else:
        s1 = curr_slot
        f = 0
        while s1 > sn1:
            for k in range(len(Slots[s1])):
                #print Slots[s1][k][2]
                if Slots[s1][k][2] == to_be_shuffled_flow:
                    f = 1
                    #print "Not Following"
                    return -1
            s1 -= 1
        return 0 
        
 
def get_conflict_lower(curr_slot,sn1,j,Slots,Conflict_Edge,Edge,FLOW,posn):
    #print "Current SLot " + str(curr_slot)
    (from_node,to_node) = find_link_curr_slot(Slots[curr_slot],j)
    #print from_node
    #print to_node
    e = find_Edge_no(from_node,to_node,Edge)
    conflict_set = Conflict_Edge[e]
    conflict = []
    independent = []
    cand_list = []
    #check current flow with other slots' flow
    for i in range(len(Slots[sn1])):
        a = Slots[sn1][i][0]
        b = Slots[sn1][i][1]
        f_id = Slots[sn1][i][2]
        if (a,b) not in conflict_set:
            independent.append(Slots[sn1][i])
        else:
            if Slots[curr_slot][posn][2] == f_id:
                conflict.append(Slots[sn1][i])
                index = i
    #print conflict
    #print j
    if len(conflict) == 0:
        #print "Hurray call for conflicting check"
        non_conflicting = []
        eligible_cand = []
        for i in range(len(Slots[sn1])):
            a = Slots[sn1][i][0]
            b = Slots[sn1][i][1]
            e = find_Edge_no(a,b,Edge)
            c_set = Conflict_Edge[e]
            count = 0
            for k in range(len(Slots[curr_slot])):
                c = Slots[curr_slot][k][0]
                d = Slots[curr_slot][k][1]
                if (c,d) in c_set:
                    count += 1
                    break
            if count == 0:
                #ith channel
                eligible_cand.append(i)
                #print "Check for flow and deadline constraint from these eligible candidates"      
        for num in range(len(eligible_cand)):
            flag1 = check_flow_constraint_lower(Slots,curr_slot,sn1,eligible_cand[num])  
            #if flag1 == -1:
            #    print "Cannot Proceed"
            if flag1 == 0:
                #print "Proceed for deadline constraint"
                to_be_shuffled_flow = Slots[sn1][eligible_cand[num]][2]
                if (int((curr_slot)/FLOW[int(to_be_shuffled_flow)].deadline) == int((sn1)/FLOW[int(to_be_shuffled_flow)].deadline)): 
                    cand_list.append(num)
            elif flag1 == 1:
                #print "Eligible to Shuffle"
                cand_list.append(num)                
    if len(conflict) == 1:
        #print "Yess check the rest with current m-1 slots and go for conflicting checking"
        conflicted_slot = sn1
        #print conflict[0]
        e = find_Edge_no(conflict[0][0],conflict[0][1],Edge)
        c_set = Conflict_Edge[e]
        c = []
        i_set = []
        for i in range(len(Slots[curr_slot])):
            a = Slots[curr_slot][i][0]
            b = Slots[curr_slot][i][1]
            if (a,b) not in c_set:
                i_set.append(Slots[curr_slot][i])
            else:
                c.append(Slots[curr_slot][i])
        if len(c) == 1:
            #print "Go for deadline and flow constraint checking"
            flag1 = check_flow_constraint_lower(Slots,curr_slot,sn1,index) 
            #if flag1 == -1:
            #    print "Cannot Proceed"
            if flag1 == 0:
                to_be_shuffled_flow = Slots[sn1][index][2]
                if (((curr_slot)/FLOW[int(to_be_shuffled_flow)].deadline) == ((sn1)/FLOW[int(to_be_shuffled_flow)].deadline)): 
                    cand_list.append(index)
            elif flag1 == 1:
                #print "Eligible to Shuffle"
                cand_list.append(index)        
                #print "Proceed for deadline constraint"
                #cand_list.append((sn1,index))
    #        elif flag1 == 0:
                #print "Eligible to Shuffle" 
    #            cand_list.append(index)                   
    #else:
    #    print "Not possible to add"     
    return cand_list 
    
    

def check_flow_constraint_upper(Slots,curr_slot,sn1,i):
    to_be_shuffled_flow = Slots[sn1][i][2] 
    
    if to_be_shuffled_flow == "-":
        return 1
    else:
        s1 = curr_slot
        f = 0
        while s1 < sn1:
            for k in range(len(Slots[s1])):
                if Slots[s1][k][2] == to_be_shuffled_flow:
                    f = 1
                    #print "curr_slot " + str(curr_slot)
                    #print "sn1 " + str(sn1)
                    #print "chan " + str(i)
                    #print "Not Following"
                    return -1
            s1 += 1
        return 0  
        
 
def get_conflict_upper(curr_slot,sn1,j,Slots,Conflict_Edge,Edge,FLOW,posn):
    #print "Current SLot " + str(curr_slot)
    (from_node,to_node) = find_link_curr_slot(Slots[curr_slot],j)
    #print from_node
    #print to_node
    e = find_Edge_no(from_node,to_node,Edge)
    conflict_set = Conflict_Edge[e]
    conflict = []
    independent = []
    cand_list = []
    #check current flow with other slots' flow
    for i in range(len(Slots[sn1])):
        a = Slots[sn1][i][0]
        b = Slots[sn1][i][1]
        f_id = Slots[sn1][i][2]
        if (a,b) not in conflict_set:
            independent.append(Slots[sn1][i])
        else:
            if Slots[curr_slot][posn][2] == f_id:
                conflict.append(Slots[sn1][i])
                index = i
    if len(conflict) == 0:
        #print "Hurray call for conflicting check"
        non_conflicting = []
        eligible_cand = []
        for i in range(len(Slots[sn1])):
            a = Slots[sn1][i][0]
            b = Slots[sn1][i][1]
            e = find_Edge_no(a,b,Edge)
            c_set = Conflict_Edge[e]
            count = 0
            for k in range(len(Slots[curr_slot])):
                c = Slots[curr_slot][k][0]
                d = Slots[curr_slot][k][1]
                if (c,d) in c_set:
                    count += 1
                    break
            if count == 0:
                #ith channel
                eligible_cand.append(i)
                #print "Check for flow and deadline constraint from these eligible candidates"      
        for num in range(len(eligible_cand)):
            flag1 = check_flow_constraint_upper(Slots,curr_slot,sn1,eligible_cand[num])  
            #if flag1 == -1:
            #    print "Cannot Proceed"
            if flag1 == 0:
                #print "Proceed for deadline constraint"
                to_be_shuffled_flow = Slots[sn1][eligible_cand[num]][2]
                if (((curr_slot)/FLOW[int(to_be_shuffled_flow)].deadline) == ((sn1)/FLOW[int(to_be_shuffled_flow)].deadline)): 
                    cand_list.append(num)
            elif flag1 == 1:
                #print "Eligible to Shuffle"
                cand_list.append(num)                
    if len(conflict) == 1:
        #print "Yess check the rest with current m-1 slots and go for conflicting checking"
        conflicted_slot = sn1
        #print conflict[0]
        e = find_Edge_no(conflict[0][0],conflict[0][1],Edge)
        c_set = Conflict_Edge[e]
        c = []
        i_set = []
        for i in range(len(Slots[curr_slot])):
            a = Slots[curr_slot][i][0]
            b = Slots[curr_slot][i][1]
            if (a,b) not in c_set:
                i_set.append(Slots[curr_slot][i])
            else:
                c.append(Slots[curr_slot][i])
        if len(c) == 1:
            #print "Go for deadline and flow constraint checking"
            flag1 = check_flow_constraint_upper(Slots,curr_slot,sn1,index) 
            #if flag1 == -1:
            #    print "Cannot Proceed"
            if flag1 == 0:
                to_be_shuffled_flow = Slots[sn1][index][2]
                if (((curr_slot)/FLOW[int(to_be_shuffled_flow)].deadline) == ((sn1)/FLOW[int(to_be_shuffled_flow)].deadline)): 
                    cand_list.append(index)
            elif flag1 == 1:
                #print "Eligible to Shuffle"
                cand_list.append(index)        
                #print "Proceed for deadline constraint"
                #cand_list.append((sn1,index))
    #        elif flag1 == 0:
                #print "Eligible to Shuffle" 
    #            cand_list.append(index)                   
    #else:
    #    print "Not possible to add"     
    return cand_list 


def filter_conflicts(curr_slot,sn1,j,Slots,Conflict_Edge,Edge,FLOW,current_posn,flag):
    cand = []
    #print sn1
    #print current_posn
    (from_node,to_node) = find_link_curr_slot(Slots[curr_slot],j)
    e = find_Edge_no(from_node,to_node,Edge)
    conflict_set = Conflict_Edge[e]
    nc_set = []
    c_set = []
    nc_set_trans = []
    f1 = Slots[curr_slot][current_posn][2]
    
    #print f1
    #print len(Slots[sn1])
    for ch in range(len(Slots[sn1])):
        a = Slots[sn1][ch][0]
        b = Slots[sn1][ch][1]
        #f_id = Slots[sn1][ch][2]
        e1 = find_Edge_no(a,b,Edge)
        #print e1
        #print conflict_set
        #for k in range(len(conflict_set)):
            #print e1
            #print conflict_set
        if (a,b) not in conflict_set:
            nc_set.append(ch)
        else:
            #print "Hi"
            c_set.append(ch)
        #print len(nc_set)
        #print len(c_set)
    if len(c_set) == 0:
        #print nc_set
        #print Slots[curr_slot][current_posn]
        #print Slots[sn1]
        temp = []
        for ch in range(len(Slots[sn1])):
            c = Slots[sn1][ch][0]
            d = Slots[sn1][ch][2]
            e2 = find_Edge_no(c,d,Edge)
            c_e = Conflict_Edge[e2]
            count = 0
            for chan in range(len(Slots[curr_slot])):
                x = Slots[curr_slot][chan][0]
                y = Slots[curr_slot][chan][1]
                e3 = find_Edge_no(x,y,Edge)
                if e3 not in c_e:
                    if Slots[curr_slot][chan][2] == "-":
                        count += 1
                    elif Slots[curr_slot][chan][2] <> Slots[sn1][ch][2]:
                        count += 1
            if count == len(Slots[curr_slot]):
                temp.append(ch)
        for j in range(len(temp)):
            non_conflicting_chan = int(temp[j])
            f = Slots[sn1][non_conflicting_chan][2]
            if f == "-":
                cand.append(non_conflicting_chan)
            else:
                rem = curr_slot/FLOW[int(f)].deadline
                thres = sn1/FLOW[int(f)].deadline
                if rem == thres:
                    if flag == -1:
                        i = curr_slot
                        constraint = 0
                        while i > sn1:
                            for ch in range(len(Slots[i])):
                                fid = Slots[i][ch][2]
                                if fid == f:
                                    #print "Flow Conflict"
                                    constraint = 1
                                    break
                            i -= 1
                        if constraint == 0:
                            cand.append(non_conflicting_chan)
                    if flag == 1:
                        i = curr_slot
                        constraint = 0
                        while i < sn1:
                            for ch in range(len(Slots[i])):
                                fid = Slots[i][ch][2]
                                if fid == f:
                                    #print "Flow Conflict"
                                    constraint = 1
                                    break
                            i += 1
                        if constraint == 0:
                            cand.append(non_conflicting_chan)
   
    if len(c_set) == 1:
        conflicting_channel = int(c_set[0])
        c = Slots[sn1][conflicting_channel][0]
        d = Slots[sn1][conflicting_channel][1]
        e2 = find_Edge_no(c,d,Edge)
        c_e = Conflict_Edge[e2]
        for ch in range(len(Slots[curr_slot])):
            if ch <> current_posn:
                a = Slots[curr_slot][ch][0]
                b = Slots[curr_slot][ch][1] 
                e3 = find_Edge_no(a,b,Edge)
                if (a,b) not in c_e:
                    #NO Transmission conflicts
                    if Slots[curr_slot][ch][2] <> Slots[sn1][conflicting_channel][2]:
                        nc_set_trans.append(ch)
        if len(nc_set_trans) > 0:
            f = Slots[sn1][conflicting_channel][2]
            rem = curr_slot/FLOW[int(f)].deadline
            thres = sn1/FLOW[int(f)].deadline
            if rem == thres:
                if flag == -1:
                    i = curr_slot
                    constraint = 0
                    while i > sn1:
                        for ch in range(len(Slots[i])):
                            fid = Slots[i][ch][2]
                            if fid == f:
                                #print "Flow Conflict"
                                constraint = 1
                                break
                        i -= 1
                    if constraint == 0:
                        cand.append(conflicting_channel)
                if flag == 1:
                    i = curr_slot
                    constraint = 0
                    while i < sn1:
                        for ch in range(len(Slots[i])):
                            fid = Slots[i][ch][2]
                            if fid == f:
                                #print "Flow Conflict"
                                constraint = 1
                                break
                        i += 1
                    if constraint == 0:
                        cand.append(conflicting_channel)
                        
            
                    
                    
    #print c_set        
    return cand        
        
    
    #if len(c_set) == 0:
    #    for chan in range(len(Slots[curr_slot])):
    #        f = Slots[sn1][chan][2]
    #        for ch in range(len(slots[curr_slot])):
    #            g = Slots[curr_slot][ch][2]
    #            if f <> g:
                    
                    
        










    

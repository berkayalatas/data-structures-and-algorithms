# take the first element from an array, then the last, then the second, then the last but one in an alternating way.
# return Boolean whether the elements are sorted


def alternatingSort(a):
    n = len(a)
    i = 0  # front pointer from the beginning of the array
    j = -1  # end pointer from the end
    if n == 1:
        return True
    elif n % 2 == 0:  # an even length array will have complete pairs for comparison
        print('Even array')  # debugging
        while i < n // 2:  # last pair for comparison is in the middle. don't need to condition on j because i, j always move together
            if a[i] > a[j]:  # if front pointer is greater than end pointer
                return False
            else:
                i += 1
                j -= 1
        return True
    else:  # an odd length array has one additional front pointer
        print('Odd array')
        while i < n // 2:  # note // gets you the integer in a division. don't confuse with %
            print(i, j)  # debugging
            if a[i] > a[j]:
                return False
            else:
                i += 1
                j -= 1
        print("one last comparison")
        print(i, i+1)
        if a[i] > a[i+1]:  # no need to involve j, just the addition front pointer and the element on the right
            return True
        else:
            return False


test1 = [-52, 2, 31, 56, 47, 29, -35]
test2 = [1, 2, 3, 4, 5]
test3 = [1, 3, 4, 5]

alternatingSort(test1)

alternatingSort(test2)

alternatingSort(test3)




def concatenationsSum(a):
    t=sum(a)
    t1=t*len(a)
    t2=sum([t*[len(str(x))-1 for x in a].count(j)*10**(j+1) for j in range(7)])
    return t1+t2


def mutateTheArray(n, a):
    return [a[0]+a[1]] + [sum(a[x-1:x+2]) for x in range(1,len(a))] if n>1 else a

def countTinyPairs(a, b, k):
    return sum([1 if int(str(x)+str(y))<k else 0 for x,y in zip(a,b[::-1])])


def meanGroups(a):
    d,e=[],[]
    for i,j in enumerate(a):
        if sum(j)/len(j)not in e:
            e+=[sum(j)/len(j)]
            d+=[[i]]
        else:
            d[e.index(sum(j)/len(j))]+=[i]
    return d

def alternatingSort(a):
    c, l=0, a[0]
    while c!=(len(a)-1)//2:
        c=-c if c<0 else -c-1
        if a[c]<=l:
            return False
        l=a[c]
    return True

""" def alternatingSort(a):
    c, l=0, a[0]
    while c!=(len(a)-1)//2:
        if c<0:
            c=-c
        else:
            c=-c-1
        if a[c]<=l:
            return False
        l=a[c]
    return True
  """



def mergeStrings(s1, s2):
    s,o1,o2='',s1,s2
    while len(s1)*len(s2)!=0:
        if o1.count(s1[0])>o2.count(s2[0]) or (o1.count(s1[0])==o2.count(s2[0]) and s1[0]>s2[0]):
            s+=s2[0]
            s2=s2[1:]
        else:
            s+=s1[0]
            s1=s1[1:]
    return s+s1+s2


def hashMap(queryType, query):
    d={}, s=0, c1=0, c2=0 

    for i,j in zip(queryType,query):
        if i == 'insert':
            d[j[0]-c1] = j[1]-c2
        elif i == 'addToValue':
            c2+=j[0]
        elif i == 'addToKey':
            c1+=j[0]
        elif i== 'get':
            s+=d[j[0]-c1]+c2
    return s
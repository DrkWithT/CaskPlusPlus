# Cask Samples

### Simple Aggregate
```
    #
        2d point structure!
    #
    agg Point
        x : int
        y : int
    end

    origin : Point = {0, 0}
```

### Simple Function
```
    #
        Does a linear search on an array of int values.
    #
    func search_int(ref numbers : int[], val item : int) : int
        let count : int = length(numbers)
        let index : int = 0

        while (index < count)
            if (numbers[index] == item)
                return index
            end

            index = index + 1
        end

        return -1
    end
```

### Recursive (divide and conquer) Function
```
    #
        Finds a^n by recursive divide and conquer strategy.
    #
    func dq_pow(val base : int , val pow : int) : int
        if (pow == 0)
            return 1
        end

        if (pow == 1)
            return base
        end

        let even_p : int = pow / 2
        let odd_p : int = (pow - 1) / 2

        if (is_even(pow) == true)
            return dq_pow(base, even_p) * dq_pow(base, even_p)
        else
            return base * dq_pow(base, odd_p) * dq_pow(base, odd_p)
        end
    end
```

```
    #
        Call of sample 3:
    #

    from io import puts, puti

    # dq_pow here...

    # main function is entry function
    func main() : int
        let base : int = 2
        let power : int = 5

        puts("a^n is ")
        puti(dq_pow(base, power))

        return 0
    end
```

/**
 * @param {...(null|boolean|number|string|Array|Object)} args
 * @return {number}
 */
var argumentsLength = function(...args) {
    
    let count;

    for(var i = 0; i < arguments.length + 1; i++) {
        count = i;
    }

    return(count);

};

/**
 * argumentsLength(1, 2, 3); // 3
 */
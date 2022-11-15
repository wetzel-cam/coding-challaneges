# TODO: make it throw error when value is out of bounds
def map(value, lower, upper, scaled_lower, scaled_upper)
  vars = method(__method__).parameters.map {|arg| arg[1]}

  # Converts each of the variables from int to float
  vars.each do |var|
    eval(var.to_s + "=" + var.to_s + ".to_f")
  end

  # if value < lower || value > upper
  #   # setup RangeError exception and resuce
  # end

  value * (scaled_upper / upper)
end
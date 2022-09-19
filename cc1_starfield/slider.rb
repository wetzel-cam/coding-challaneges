require 'ruby2d'

class Slider
  def initialize
    @center_x, @center_y = 300, 150
    @max_width, @max_height = 400, 150
    @background = Rectangle.new(
      x: @center_x - (@max_width / 2), y: @center_y - (@max_height / 2),
      width: @max_width, height: @max_height,
      color: 'blue',
      z: 20
    )

    background_x_center = (@background.x + (@background.width / 2))
    background_y_center = (@background.y + (@background.height / 2))

    x_margin, y_margin = 10, 10
    width, height = @background.x - (2 * x_margin), @background.y - (2 * y_margin)
    @range_bar = Rectangle.new(
      x: background_x_center - (width / 2), y: background_y_center - (height / 2),
      width: width, height: height,
      color: 'green',
      z: 21
    )
  end

  attr_accessor :center_x
  attr_accessor :center_y
end

set viewport_width: 100
set viewport_height: 150

quad = Quad.new(
  x1: 50, y1: 98,
  x2: 71, y2: 91,
  x3: 81, y3: 51,
  x4: 30, y4: 40,
  z: 1
)

def distance(x1, y1, x2, y2)
  Math.sqrt((x2 - x1)**2 + (y2-y1)**2)
end

a = Line.new(
  x1: quad.x1, y1: quad.y1,
  x2: quad.x2, y2: quad.y2
)
b = Line.new(
  x1: quad.x2, y1: quad.y2,
  x2: quad.x3, y2: quad.y3
)
c = Line.new(
  x1: quad.x3, y1: quad.y3,
  x2: quad.x4, y2: quad.y4
)
d = Line.new(
  x1: quad.x1, y1: quad.y1,
  x2: quad.x4, y2: quad.y4
)
p = Line.new(
  x1: quad.x1, y1: quad.y1,
  x2: quad.x3, y2: quad.y3,
  width: 1,
  color: 'red',
  z: 1
)
q = Line.new(
  x1: quad.x4, y1: quad.y4,
  x2: quad.x2, y2: quad.y2,
  width: 1,
  color: 'red',
  z: 1
)

<<<<<<< HEAD
# def slope(line)
#   # if line.m.empty?
#   #   ((line.y2 - line.y1) / (line.x2 - line.x1))
#   # else
#   #   line.m
#   # end
#   m = ((line.y2.to_f - line.y1) / (line.x2 - line.x1))
#   [m, get_zero_value(line, m)]
# end

# def get_zero_value(line, m)
#   zero_value = line.y1 - (m * line.x1)
# end

# a_func = slope(a)

# a_tan = Line.new(
#   x1: a.x1, y1: a_func[0] * a.x1 + a_func[1],
#   x2: a.x2, y2: a_func[0] * a.x2 + a_func[1],
#   width: 0.5,
#   color: 'blue',
#   z: 3
# )

# b_func = slope(b)

# b_tan = Line.new(
#   x1: b.x1, y1: b_func[0] * b.x1 + b_func[1],
#   x2: b.x2, y2: b_func[0] * b.x2 + b_func[1],
#   width: 0.5,
#   color: 'blue',
#   z: 3
# )



# a_d = distance(quad.x1,quad.y1,quad.x2,quad.y2)
# b_d = distance(quad.x2,quad.y2,quad.x3,quad.y3)
# c_d = distance(quad.x3,quad.y3,quad.x4,quad.y4)
# d_d = distance(quad.x4,quad.y4,quad.x1,quad.y1)
# p_d = p.length
# q_d = q.length

# m_d = 0.5 * (Math.sqrt((-1 * a_d**2) + b_d**2 - c_d**2 + d_d**2 + p_d**2 + q_d**2))
# n_d = 0.5 * (Math.sqrt(a_d**2 - b_d**2 + c_d**2 - d_d**2 + p_d**2 + q_d**2))

puts a.coords
=======

def slope(line)
  # if line.m.empty?
  #   ((line.y2 - line.y1) / (line.x2 - line.x1))
  # else
  #   line.m
  # end
  ((line.y2 - line.y1) / (line.x2 - line.x1))
end

m = slope(a)

a_func = Line.new(
  x1: 0, y1: 114 + (2 / 3),
  x2: 100, y2: -1 * (100 / 3) + (114 + (2 / 3)),
  width: 0.5,
  color: 'blue',
  z: 3
)


a_d = distance(quad.x1,quad.y1,quad.x2,quad.y2)
b_d = distance(quad.x2,quad.y2,quad.x3,quad.y3)
c_d = distance(quad.x3,quad.y3,quad.x4,quad.y4)
d_d = distance(quad.x4,quad.y4,quad.x1,quad.y1)
p_d = p.length
q_d = q.length

m_d = 0.5 * (Math.sqrt((-1 * a_d**2) + b_d**2 - c_d**2 + d_d**2 + p_d**2 + q_d**2))
n_d = 0.5 * (Math.sqrt(a_d**2 - b_d**2 + c_d**2 - d_d**2 + p_d**2 + q_d**2))

puts m_d
puts n_d

>>>>>>> 625a8a083b434867c2931746bdd40a632b20df71

show
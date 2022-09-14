require '../utils.rb'

class Star

  @@rand_pos = Random.new
  
  def initialize
    @@x_offset = @@window.width / 2
    @@y_offset = @@window.height / 2
    @z_factor = @@rand_pos.rand(@@window.width)

    @x_pos = @@rand_pos.rand(-@@window.width..@@window.width)
    @y_pos = @@rand_pos.rand(-@@window.height..@@window.height)

    @circle = Circle.new(
      x: @x_pos,
      y: @y_pos,
      radius: 8,
      sectors: 8,
      color: 'white'
    )
  end

  attr_reader :circle

  def self.window=(window)
    @@window = window
  end

  def update
    @z_factor -= 10

    if (@z_factor < 1)
      @z_factor = @@window.width
      @x_pos = @@rand_pos.rand((-@@window.width)..@@window.width)
      @y_pos = @@rand_pos.rand((-@@window.height)..@@window.height)
    end

    # The draw location is a scaled value based on the true position
    # i.e. all calculations are handled, then a translation is done from raw values to canvas
    @circle.x = map(@x_pos.fdiv(@z_factor), 0, 1, 0, @@window.width) + @@x_offset
    @circle.y = map(@y_pos.fdiv(@z_factor), 0, 1, 0, @@window.height) + @@y_offset
  end
end


#require './starfield.rb'
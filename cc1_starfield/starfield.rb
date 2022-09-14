require 'ruby2d'
require './star.rb'

def setup
  set title: "Starfield"
  set width: 800, height: 800

  $stars = []
  Star.window = Window
  (1..400).each { |counter| add_star }

  $fps_textbox = Text.new(0, x: 20, y: 20, size: 45, color: 'green', z: 10)
end

def add_star
  $stars.push(Star.new)
end


setup

update do
  $stars.each {|star| star.update}
  $fps_textbox.text = "FPS: #{(get :fps).floor}"
end

show
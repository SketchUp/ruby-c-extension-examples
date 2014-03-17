# This file should be required by a file that has defined `RELEASE` to be the
# name of the build folder where the binaries are located.

if SKETCHUP_CONSOLE.respond_to?(:show)
  SKETCHUP_CONSOLE.show
else
  Sketchup.send_action("showRubyPanel:")
end

prostatus = Sketchup.is_pro? ? "Pro" : ""
puts "SketchUp #{prostatus} #{Sketchup.version}"
puts "Loading '#{RELEASE}' build..."

ruby_path = File.dirname(__FILE__)
project_path = File.expand_path( File.join(ruby_path, '..') )
binary_path = File.join(project_path, RELEASE)

pattern = File.join(binary_path, "*.{so,bundle}")
Dir.glob(pattern).each { |library|
  require library
}

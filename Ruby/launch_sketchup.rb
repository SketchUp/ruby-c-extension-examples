# This file should be required by a file that has defined `RELEASE` to be the
# name of the build folder where the binaries are located.

configuration, platform = ARGV[0].split(':')

if SKETCHUP_CONSOLE.respond_to?(:show)
  SKETCHUP_CONSOLE.show
else
  Sketchup.send_action("showRubyPanel:")
end

pro_status = Sketchup.is_pro? ? "Pro" : ""
puts "SketchUp #{pro_status} #{Sketchup.version}"
puts "Loading '#{configuration}' (#{platform}) build..."

ruby_path = File.dirname(__FILE__)
project_path = File.expand_path( File.join(ruby_path, '..') )
if platform == 'x64'
  binary_path = File.join(project_path, configuration, platform)
else
  binary_path = File.join(project_path, configuration)
end

puts ruby_path
puts project_path
puts binary_path

pattern = File.join(binary_path, "*.{so,bundle}")
Dir.glob(pattern).each { |library|
  puts "Requiring #{library}"
  require library
}
